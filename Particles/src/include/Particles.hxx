/**
 * @file Particles.hxx
 * 
 * This file contains some predefined structs that defines the parameters
 * needed for a particle in order to be used on a <Particles>Container instance.
 */

namespace Particles {
// Struct to managing null particles
struct BaseParticleData {
  enum {
    // Particle position
    x = 0, y, z,
    // Particle Velocity
    vx, vy, vz,
    // Number of attributes on the struct
    n_attributes,
  }; // enum
}; // struct PhotonsData

// Struct to managing null particles
struct PhotonsData {
  enum {
    // Photon position
    x = 0, y, z,
    // Photon Velocity
    vx, vy, vz,
    // Photon Energy
    E,
    // Number of attributes on the struct
    n_attributes,
  }; // enum
}; // struct PhotonsData

// Struct to managing massive particles
struct MassiveParticleData {
  enum {
    // Massive particle position
    x = 0, y, z,
    // Massive particle velocity
    vx, vy, vz,
    // Massive particle Energy
    E,
    // Massive particle mass
    m,
    // Number of attributes on the struct
    n_attributes,
  }; // enum
}; // struct MassiveParticleData

} // namespace Particles
