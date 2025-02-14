/**
 * This file is part of janus_client project.
 * Author:    Jackie Ou
 * Created:   2020-10-18
 **/

#pragma once

#include <QtCore/QObject>
#include <memory>
#include "participant.h"
#include "i_video_room_listener.h"


class VideoRoomListenerProxy 
	: public QObject
	, public vi::IVideoRoomListener
	, public std::enable_shared_from_this<VideoRoomListenerProxy>
{
	Q_OBJECT

public:
	VideoRoomListenerProxy(QObject *parent);
	~VideoRoomListenerProxy();

private:
	// IVideoRoomListener
	void onMediaState(bool isActive, const std::string& reason) override;

	void onCreateParticipant(std::shared_ptr<vi::Participant> participant) override;

	void onUpdateParticipant(std::shared_ptr<vi::Participant> participant) override;

	void onRemoveParticipant(std::shared_ptr<vi::Participant> participant) override;

	void onCreateStream(uint64_t pid, rtc::scoped_refptr<webrtc::MediaStreamInterface> stream) override;

	void onRemoveStream(uint64_t pid, rtc::scoped_refptr<webrtc::MediaStreamInterface> stream) override;

signals:
	void mediaState(bool isActive, const std::string& reason);

	void createParticipant(std::shared_ptr<vi::Participant> participant);

	void updateParticipant(std::shared_ptr<vi::Participant> participant);

	void removeParticipant(std::shared_ptr<vi::Participant> participant);

	void createStream(uint64_t pid, rtc::scoped_refptr<webrtc::MediaStreamInterface> stream);

	void removeStream(uint64_t pid, rtc::scoped_refptr<webrtc::MediaStreamInterface> stream);
};
