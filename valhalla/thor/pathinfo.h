#ifndef VALHALLA_THOR_PATHINFO_H_
#define VALHALLA_THOR_PATHINFO_H_

#include <unordered_map>
#include <valhalla/baldr/graphid.h>
#include <valhalla/sif/costconstants.h>

namespace valhalla {
namespace thor {

/**
 * Simple structure to pass path information from PathAlgorithm
 * to TripPathBuilder
 */
struct PathInfo {
  sif::TravelMode mode;    // Travel mode along this edge
  uint8_t travel_type;     // Travel type along this edge
  uint32_t elapsed_time;   // Elapsed time in seconds to the end of the edge
  uint32_t trip_id;        // Trip Id (0 if not a transit edge).
  baldr::GraphId edgeid;   // Directed edge Id

  PathInfo(const sif::TravelMode m, const uint8_t tt, const uint32_t t,
           const baldr::GraphId& edge, const uint32_t tripid)
      : mode(m),
        travel_type(tt),
        elapsed_time(t),
        trip_id(tripid),
        edgeid(edge) {
  }
};

}
}

#endif  // VALHALLA_THOR_PATHINFO_H_
