#include "../../../CarpetX/CarpetX/src/driver.hxx"
#include "./include/Particles.hxx"
#include "./include/ParticlesContainer.hxx"

using ParticleData = Particles::MassiveParticleData;

using PC = Containers::PhotonsContainer<ParticleData>;
std::vector<std::unique_ptr<PC>> g_nupcs;

extern "C" void test_setup(CCTK_ARGUMENTS) {
  DECLARE_CCTK_PARAMETERS;

  for (int patch = 0; patch < CarpetX::ghext->num_patches(); ++patch) {
    const auto &patchdata = CarpetX::ghext->patchdata.at(patch);
    g_nupcs.push_back(std::make_unique<PC>(patchdata.amrcore.get()));
  }
}

extern "C" void test(CCTK_ARGUMENTS) {
  DECLARE_CCTK_PARAMETERS;
  g_nupcs[0]->initialize();
  g_nupcs[0]->evolve();
}
