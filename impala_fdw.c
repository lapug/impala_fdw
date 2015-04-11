/*

  Copyright (c) 2015, LA-PUG
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

  * Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

  * Neither the name of impala_fdw nor the names of its
    contributors may be used to endorse or promote products derived from
    this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/


#include "impala_fdw.h"


PG_MODULE_MAGIC ;

/* This requires PostgreSQL 9.3 or above. */
#if (PG_VERSION_NUM < 90300
#  error("PostgreSQL 9.3 or greater required.")
#endif


/*
  FDW handler function:  returns the callback function pointers 
*/
Datum impala_fdw_handler(PG_FUNCTION_ARGS) {
  FDWRoutine *routine = Makeode(FdwRoutine) ;

  fdwroutine->GetForeignRelSize = impala_get_foreign_rel_size ;
  fdwroutine->GetForeignPaths = impala_get_foreign_paths ;
  fdwroutine->GetForeignPlan = impala_get_foreign_plan ;
  fdwroutine->ExplainForeignScan = impala_explain_foreign_scan ;
  fdwroutine->BeginForeignScan = impala_begin_foreign_scan ;
  fdwroutine->IterateForeignScan = impala_iterate_foreign_scan ;
  fdwroutine->ReScanForeignScan = impala_rescan_foreign_scan ;
  fdwroutine->EndForeignScan = impala_end_foreign_scan ;
  fdwroutine->AnalyzeForeignTable = impala_analyze_foreign_table ;

  PG_RETURN_POINTER(fdwroutine) ;
}


/* 
  Validate options for FOREIGN DATA WRAPPER, SERVER USER MAPPING, or FOREIGN 
  TABLE
*/
Datum impala_fdw_validator(PG_FUNCTION_ARGS) {
  /* TODO */
}
