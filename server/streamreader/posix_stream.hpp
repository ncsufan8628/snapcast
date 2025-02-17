/***
    This file is part of snapcast
    Copyright (C) 2014-2021  Johannes Pohl

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
***/

#ifndef POSIX_STREAM_HPP
#define POSIX_STREAM_HPP

// local headers
#include "asio_stream.hpp"

namespace streamreader
{

using boost::asio::posix::stream_descriptor;


/// Reads and decodes PCM data from a file descriptor
/**
 * Reads PCM from a file descriptor and passes the data to an encoder.
 * Implements EncoderListener to get the encoded data.
 * Data is passed to the PcmStream::Listener
 */
class PosixStream : public AsioStream<stream_descriptor>
{
public:
    /// ctor. Encoded PCM data is passed to the PipeListener
    PosixStream(PcmStream::Listener* pcmListener, boost::asio::io_context& ioc, const ServerSettings& server_settings, const StreamUri& uri);

protected:
    void connect() override;
    void do_disconnect() override;
    std::string lastException_;
    size_t dryout_ms_;
    int idle_bytes_;
    int max_idle_bytes_;
};

} // namespace streamreader

#endif
