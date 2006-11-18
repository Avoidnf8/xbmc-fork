/*!
\file GUIControlGroup.h
\brief 
*/

#pragma once

#include "GUIControl.h"

/*!
 \ingroup controls
 \brief group of controls, useful for remembering last control + animating/hiding together
 */
class CGUIControlGroup : public CGUIControl
{
public:
  CGUIControlGroup();
  CGUIControlGroup(DWORD dwParentID, DWORD dwControlId, float posX, float posY, float width, float height);
  virtual ~CGUIControlGroup(void);
  virtual void Render();
  virtual bool OnAction(const CAction &action);
  virtual bool OnMessage(CGUIMessage& message);
  virtual bool HasFocus() const;
  virtual void PreAllocResources();
  virtual void AllocResources();
  virtual void FreeResources();
  virtual void DynamicResourceAlloc(bool bOnOff);
  virtual bool CanFocus() const;

  virtual bool HitTest(float posX, float posY) const;
  virtual bool CanFocusFromPoint(float posX, float posY, CGUIControl **control) const;

  virtual void SetInitialVisibility();

  virtual void UpdateEffectState(DWORD currentTime);
  virtual bool IsAnimating(ANIMATION_TYPE anim);
  virtual void QueueAnimation(ANIMATION_TYPE anim);

  virtual bool HasID(DWORD dwID) const;
  virtual bool HasVisibleID(DWORD dwID) const;

  int GetFocusedControlID() const;
  CGUIControl *GetFocusedControl() const;
  const CGUIControl *GetControl(int id) const;
  CGUIControl *GetFirstFocusableControl(int id);

  virtual void AddControl(CGUIControl *control);
  virtual void RemoveControl(int id);
  virtual void ClearAll();
  void SetDefaultControl(DWORD id) { m_defaultControl = id; };

  virtual void SaveStates(vector<CControlState> &states);

  virtual bool IsGroup() const { return true; };

protected:
  virtual void Animate(DWORD currentTime);

  // sub controls
  vector<CGUIControl *> m_children;
  typedef vector<CGUIControl *>::iterator iControls;
  typedef vector<CGUIControl *>::const_iterator ciControls;

  int m_defaultControl;
  int m_focusedControl;

  DWORD m_renderTime;
};
