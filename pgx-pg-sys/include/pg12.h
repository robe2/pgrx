#include "postgres.h"
#include "funcapi.h"
#include "miscadmin.h"
#include "pgstat.h"
#include "access/amapi.h"
#include "access/genam.h"
#include "access/htup.h"
#include "access/htup_details.h"
#include "access/relation.h"
#include "access/reloptions.h"
#include "access/relscan.h"
#include "access/skey.h"
#include "access/sysattr.h"
#include "access/tableam.h"
#include "access/xact.h"
#include "catalog/index.h"
#include "catalog/namespace.h"
#include "catalog/pg_enum.h"
#include "catalog/pg_type.h"
#include "commands/dbcommands.h"
#include "commands/event_trigger.h"
#include "commands/tablecmds.h"
#include "catalog/dependency.h"
#include "catalog/objectaddress.h"
#include "catalog/pg_trigger.h"
#include "commands/trigger.h"
#include "executor/executor.h"
#include "executor/spi.h"
#include "foreign/fdwapi.h"
#include "foreign/foreign.h"
#include "nodes/execnodes.h"
#include "nodes/extensible.h"
#include "nodes/makefuncs.h"
#include "nodes/nodeFuncs.h"
#include "nodes/nodes.h"
#include "nodes/pathnodes.h"
#include "nodes/print.h"
#include "nodes/replnodes.h"
#include "nodes/supportnodes.h"
#include "nodes/tidbitmap.h"
#include "nodes/value.h"
#include "optimizer/cost.h"
#include "optimizer/clauses.h"
#include "optimizer/optimizer.h"
#include "optimizer/paths.h"
#include "optimizer/pathnode.h"
#include "optimizer/planner.h"
#include "optimizer/restrictinfo.h"
#include "parser/parse_func.h"
#include "parser/parse_type.h"
#include "postmaster/bgworker.h"
#include "storage/block.h"
#include "storage/lwlock.h"
#include "storage/procarray.h"
#include "storage/itemptr.h"
#include "storage/ipc.h"
#include "tcop/tcopprot.h"
#include "tcop/utility.h"
#include "utils/builtins.h"
#include "utils/date.h"
#include "utils/geo_decls.h"
#include "utils/guc.h"
#include "utils/json.h"
#include "utils/jsonb.h"
#include "utils/syscache.h"
#include "utils/lsyscache.h"
#include "utils/memutils.h"
#include "utils/palloc.h"
#include "utils/rel.h"
#include "utils/relcache.h"
#include "utils/selfuncs.h"
#include "utils/snapmgr.h"
#include "utils/typcache.h"
