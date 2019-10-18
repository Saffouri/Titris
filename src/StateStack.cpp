#include "StateStack.h"

void StateStack::AddState(StateRef newState, bool isReplacing)
{
    m_isAdding = true;
    m_isReplacing = isReplacing;
    m_newState = std::move(newState);
}

void StateStack::SwitchState(StateRef newState)
{
    AddState(std::move(newState), true);
}

void StateStack::RemoveState()
{
    m_isRemoving = true;
}

void StateStack::ProcessStateChanges()
{
    if (m_isRemoving)
    {
        if (!m_stateStack.empty())
        {
            m_stateStack.pop();
            if (!m_stateStack.empty())
            {
                GetActiveState()->Resume();
            }
        }
        m_isRemoving = false;
    }

    if (m_isAdding)
    {
        if (m_isReplacing)
        {
            if (!m_stateStack.empty())
            {
                m_stateStack.pop();
            }
            else
            {
                GetActiveState()->Pause();
            }
        }
        m_stateStack.push(std::move(m_newState));
        GetActiveState()->Init();
        m_isAdding = false;
    }
}

const StateRef& StateStack::GetActiveState() const
{
    return m_stateStack.top();
}

bool StateStack::IsEmpty() const
{
    return m_stateStack.empty();
}