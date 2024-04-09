#include "headers/bbDispatch.h"
#include "headers/bbSystemIncludes.h"
#include "headers/bbGame.h"
#include "headers/bbMouse.h"
#include "headers/bbCharacter.h"

int32_t EventDispatch(int32_t map){ //TODO reconsider argument

    bbMapConstants* constants = &g_Game->m_Maps[map]->p_Constants;
    sfEvent event;
    bbMouseEvent mouseEvent;

    while(sfRenderWindow_pollEvent(g_Game->m_Window, &event)) {
        switch (event.type) {
            case sfEvtClosed:
                exit(EXIT_SUCCESS);
                break;
            case sfEvtMouseButtonPressed:

                mouseEvent.m_ScreenCoords.x = event.mouseButton.x * constants->ScreenPPP;
                mouseEvent.m_ScreenCoords.y = event.mouseButton.y * constants->ScreenPPP;
                mouseEvent.m_type = event.mouseButton.button == sfMouseLeft ? f_MouseLeft : f_MouseRight;

                EventMouse(&mouseEvent, map);
                break;
            case sfEvtMouseMoved:
                mouseEvent.m_ScreenCoords.x = event.mouseMove.x * constants->ScreenPPP;
                mouseEvent.m_ScreenCoords.y = event.mouseMove.y * constants->ScreenPPP;
                mouseEvent.m_type = f_MouseMove;
                EventMouse(&mouseEvent, map);
                break;
            case sfEvtKeyPressed:
                if (event.key.code == sfKeyReturn){
                    Event_inputChar('\n', map);
                    break;
                }
                if (event.key.shift == sfTrue){
                    switch (event.key.code) {
                        case sfKeyA:
                            Event_inputChar('A', map);
                            break;
                        case sfKeyB:
                            Event_inputChar('B', map);
                            break;
                        case sfKeyC:
                            Event_inputChar('C', map);
                            break;
                        case sfKeyD:
                            Event_inputChar('D', map);
                            break;
                        case sfKeyE:
                            Event_inputChar('E', map);
                            break;
                        case sfKeyF:
                            Event_inputChar('F', map);
                            break;
                        case sfKeyG:
                            Event_inputChar('G',map);
                            break;
                        case sfKeyH:
                            Event_inputChar('H',map);
                            break;
                        case sfKeyI:
                            Event_inputChar('I',map);
                            break;
                        case sfKeyJ:
                            Event_inputChar('J',map);
                            break;
                        case sfKeyK:
                            Event_inputChar('K',map);
                            break;
                        case sfKeyL:
                            Event_inputChar('L',map);
                            break;
                        case sfKeyM:
                            Event_inputChar('M',map);
                            break;
                        case sfKeyN:
                            Event_inputChar('N',map);
                            break;
                        case sfKeyO:
                            Event_inputChar('O',map);
                            break;
                        case sfKeyP:
                            Event_inputChar('P',map);
                            break;
                        case sfKeyQ:
                            Event_inputChar('Q',map);
                            break;
                        case sfKeyR:
                            Event_inputChar('R',map);
                            break;
                        case sfKeyS:
                            Event_inputChar('S',map);
                            break;
                        case sfKeyT:
                            Event_inputChar('T',map);
                            break;
                        case sfKeyU:
                            Event_inputChar('U',map);
                            break;
                        case sfKeyV:
                            Event_inputChar('V',map);
                            break;
                        case sfKeyW:
                            Event_inputChar('W',map);
                            break;
                        case sfKeyX:
                            Event_inputChar('X',map);
                            break;
                        case sfKeyY:
                            Event_inputChar('Y',map);
                            break;
                        case sfKeyZ:
                            Event_inputChar('Z',map);
                            break;
                    }

                }
                if (event.key.shift == sfFalse){
                    switch (event.key.code) {
                        case sfKeyA:
                            Event_inputChar('a', map);
                            break;
                        case sfKeyB:
                            Event_inputChar('b', map);
                            break;
                        case sfKeyC:
                            Event_inputChar('c', map);
                            break;
                        case sfKeyD:
                            Event_inputChar('d', map);
                            break;
                        case sfKeyE:
                            Event_inputChar('e', map);
                            break;
                        case sfKeyF:
                            Event_inputChar('f', map);
                            break;
                        case sfKeyG:
                            Event_inputChar('g',map);
                            break;
                        case sfKeyH:
                            Event_inputChar('h',map);
                            break;
                        case sfKeyI:
                            Event_inputChar('i',map);
                            break;
                        case sfKeyJ:
                            Event_inputChar('j',map);
                            break;
                        case sfKeyK:
                            Event_inputChar('k',map);
                            break;
                        case sfKeyL:
                            Event_inputChar('l',map);
                            break;
                        case sfKeyM:
                            Event_inputChar('m',map);
                            break;
                        case sfKeyN:
                            Event_inputChar('n',map);
                            break;
                        case sfKeyO:
                            Event_inputChar('o',map);
                            break;
                        case sfKeyP:
                            Event_inputChar('p',map);
                            break;
                        case sfKeyQ:
                            Event_inputChar('q',map);
                            break;
                        case sfKeyR:
                            Event_inputChar('r',map);
                            break;
                        case sfKeyS:
                            Event_inputChar('s',map);
                            break;
                        case sfKeyT:
                            Event_inputChar('t',map);
                            break;
                        case sfKeyU:
                            Event_inputChar('u',map);
                            break;
                        case sfKeyV:
                            Event_inputChar('v',map);
                            break;
                        case sfKeyW:
                            Event_inputChar('w',map);
                            break;
                        case sfKeyX:
                            Event_inputChar('x',map);
                            break;
                        case sfKeyY:
                            Event_inputChar('y',map);
                            break;
                        case sfKeyZ:
                            Event_inputChar('z',map);
                            break;
                    }

                }

            default:
                bbPrintf("sfEvent not handled\n");
        }
    }
    return f_Success;
}
