#pragma once
#include "IState.h"
#include <memory>
#include <stack>

typedef std::unique_ptr<IState> StateRef;

class StateStack
{
    public:
        void AddState(StateRef newState, bool isReplacing = false);
        void SwitchState(StateRef newState);
        void RemoveState();
        void ProcessStateChanges();
        const StateRef& GetActiveState() const;
        bool IsEmpty() const;
    private:
        std::stack<StateRef> m_stateStack;
        StateRef m_newState;
        bool m_isAdding = false;
        bool m_isRemoving = false;
        bool m_isReplacing = false;
};