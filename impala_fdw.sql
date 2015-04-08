-- 


-- Make users install via CREATE EXTENSION rather than sourcing this directly
\echo Use "CREATE EXTENSION impala_fdw" to install. \q

CREATE FUNCTION impala_fdw_handler()
RETURNS fdw_handler
AS 'MODULE_PATHNAME'
LANGUAGE C STRICT ;

CREATE FUNCTION impala_fdw_validator(text[], oid)
RETURNS void
AS 'MODULE_PATHNAME'
LANGUAGE C STRICT ;

CREATE FOREIGN DATA WRAPPER impala_fdw
  HANDLER impala_fdw_handler
  VALIDATOR impala_fdw_validator ;
