/**
 * @file ParticlesContainer.hxx
 *
 * @brief Contains the Iterator and Particles namespaces.
 *
 * This file contains the definition of the Iterator and Particles namespaces.
 *
 * The Iterator namespace contains the definition to a convenient class to
 * iterate over the particles: the ParticleIterator class. The Particles
 * namespace defines the different <Particles>Container classes, where
 * <Particle> depend on the equations to solve. This is the concrete class that
 * implements the abstract methods defined on the abstract
 * BaseParticlesContainer class.
 */

#ifndef PARTICLESCONTAINER_H
#define PARTICLESCONTAINER_H

// Import libraries
#include "BaseParticlesContainer.hxx"
#include <AMReX_AmrParticles.H>
#include <AMReX_MultiFab.H>
#include <AMReX_MultiFabUtil.H>
#include <AMReX_Particles.H>
#include <AMReX_REAL.H>
#include <cctk_Arguments.h>

static constexpr const char *INFO = "INFO (GeodesicsIntegratorX/Particles): ";

namespace Iterator {

template <typename StructType>
class ParticleIterator
    : public amrex::ParIter<0, 0, StructType::n_attributes, 0> {
public:
  using Base = amrex::ParIter<0, 0, StructType::n_attributes, 0>;
  using Base::ParIter;
  using RealVector = typename amrex::ParIter<
      0, 0, StructType::n_attributes>::ContainerType::RealVector;

  const std::array<RealVector, StructType::n_attributes> &GetAttribs() const {
    return this->GetStructOfArrays().GetRealData();
  }

  std::array<RealVector, StructType::n_attributes> &GetAttribs() {
    return this->GetStructOfArrays().GetRealData();
  }

  const RealVector &GetAttribs(int comp) const {
    return this->GetStructOfArrays().GetRealData(comp);
  }

  RealVector &GetAttribs(int comp) {
    return this->GetStructOfArrays().GetRealData(comp);
  }
}; // class ParicleIterator

} // namespace Iterator

namespace Containers {

// #############################################################################
//                   PhotonsContainer::CLASS INITIALIZATION
// #############################################################################
template <typename StructType>
class PhotonsContainer
    : public BaseParticlesContainer::BaseParticlesContainer<StructType> {

public:
  PhotonsContainer(amrex::AmrCore *amr_core)
      : BaseParticlesContainer::BaseParticlesContainer<StructType>(amr_core) {}

  void initialize() override;
  void evolve() override;
}; // PhotonsContainer class

// ##############################################################################
//                   PhotonsContainer::METHODS DECLARATION
// ##############################################################################

template <typename StructType> void PhotonsContainer<StructType>::initialize() {
  std::cout << INFO << "Initializing Particles with "
            << StructType::n_attributes << " attributes." << std::endl;
} // PhotonsContainer::initialize method

template <typename StructType> void PhotonsContainer<StructType>::evolve() {
  std::cout << INFO << "Evolving Particles" << std::endl;
} // PhotonsContainer::evolve

// #############################################################################
//                   MassiveContainer::CLASS INITIALIZATION
// #############################################################################

template <typename StructType>
class MassiveContainer
    : public BaseParticlesContainer::BaseParticlesContainer<StructType> {};// MassiveContainer class

} // namespace Containers

#endif // !PARTICLESCONTAINER_H
