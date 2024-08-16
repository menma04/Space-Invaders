#pragma once
#include<SFML/Graphics/RenderWindow.hpp>
#include<SFML/Window/Event.hpp>

namespace Event {
	enum class ButtonState {
		PRESSED,
		HELD,
		RELEASED
	};
	class EventService {
	private:
		ButtonState left_mouse_button_state;
		ButtonState right_mouse_button_state;
		ButtonState left_arrow_button_state;
		ButtonState right_arrow_button_state;
		ButtonState A_button_state;
		ButtonState D_button_state;

		void updateMouseButtonsState(ButtonState& current_button_state, sf::Mouse::Button mouse_button);
		void updateKeyboardButtonsState(ButtonState& current_button_state, sf::Keyboard::Key Keyboard_button);


		sf::RenderWindow* game_window;
		sf::Event game_event;

		bool isGameWindowOpen();
		bool gameWindowWasClosed();
		bool hasQuitGame();
	public:

		EventService();
		~EventService();

		void initialize();
		void update();
		bool pressedLeftMouseButton();
		bool pressedRightMouseButton();
		void processEvents();
		bool pressedEscapeKey();
		bool isKeyboardEvent();
		bool pressedLeftKey();
		bool pressedRightKey();

		bool pressedAKey();
		bool pressedDKey();
	};
}