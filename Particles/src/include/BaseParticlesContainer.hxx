/**
 * @file BaseParticlesContainer.hxx
 *
 * @ brief Contains the BaseParticlesContainer class definition.
 * 
 * This file contains the BaseParticlesContainer abstract class. This
 * class extends from amrex::AmrParticleContainer and contains the particles data
 * using an array of structs (AoS).
 */
#ifndef BASEPARTICLESCONTAINER_HXX
#define BASEPARTICLESCONTAINER_HXX

// Include libraries
#include <cctk_Arguments.h>
#include <AMReX_Particles.H>
#include <AMReX_AmrParticles.H>

// Starting the namespace
namespace BaseParticlesContainer {

template <typename StructType>
class BaseParticlesContainer : public amrex::AmrParticleContainer<0, 0, StructType::n_attributes, 0> {
public:
  BaseParticlesContainer(amrex::AmrCore *amr_core) : amrex::AmrParticleContainer<0, 0, StructType::n_attributes, 0>(amr_core) {}

  virtual void initialize() = 0;
  virtual void evolve() = 0;
  void outputParticlesAscii(CCTK_ARGUMENTS);
  void outputParticlesPlot(CCTK_ARGUMENTS);
}; // class BaseParticlesContainer

} // namespace BaseParticlesContainer

#endif // !BASEPARTICLESCONTAINER_HXX
