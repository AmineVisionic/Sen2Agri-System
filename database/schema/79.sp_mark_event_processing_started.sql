﻿CREATE OR REPLACE FUNCTION sp_mark_event_processing_started(
IN _event_id int
) RETURNS void AS $$
BEGIN

	UPDATE event
	SET processing_started_timestamp = now()
	WHERE id = _event_id;

END;
$$ LANGUAGE plpgsql;

