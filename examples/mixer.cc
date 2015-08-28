/*
  libSDL2pp - C++11 bindings/wrapper for SDL2
  Copyright (C) 2015 Dmitry Marakasov <amdmi3@amdmi3.ru>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include <SDL2pp/SDL.hh>
#include <SDL2pp/SDLMixer.hh>
#include <SDL2pp/Mixer.hh>
#include <SDL2pp/Chunk.hh>

using namespace SDL2pp;

int main() try {
	SDL sdl(SDL_INIT_AUDIO);
	SDLMixer mixerlib(MIX_INIT_OGG);
	Mixer mixer(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096);

	Chunk chunk(TESTDATA_DIR "/test.ogg");

	int chan;

	chan = mixer.PlayChannel(-1, chunk);
	std::cerr << "Playing sound on channel " << chan << "\n";

	SDL_Delay(500);

	chan = mixer.PlayChannel(-1, chunk);
	std::cerr << "Playing sound on channel " << chan << "\n";

	SDL_Delay(1000);

	chan = mixer.PlayChannel(-1, chunk);
	std::cerr << "Playing sound on channel " << chan << "\n";

	SDL_Delay(4500);

	return 0;
} catch (std::exception& e) {
	std::cerr << "Error: " << e.what() << std::endl;
	return 1;
}
