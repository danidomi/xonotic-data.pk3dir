#ifdef INTERFACE
CLASS(XonoticHUDScoreDialog) EXTENDS(XonoticRootDialog)
	METHOD(XonoticHUDScoreDialog, fill, void(entity))
	ATTRIB(XonoticHUDScoreDialog, title, string, "Score Panel")
	ATTRIB(XonoticHUDScoreDialog, color, vector, SKINCOLOR_DIALOG_TEAMSELECT)
	ATTRIB(XonoticHUDScoreDialog, intendedWidth, float, 0.4)
	ATTRIB(XonoticHUDScoreDialog, rows, float, 15)
	ATTRIB(XonoticHUDScoreDialog, columns, float, 4)
	ATTRIB(XonoticHUDScoreDialog, name, string, "HUDscore")
ENDCLASS(XonoticHUDScoreDialog)
#endif

#ifdef IMPLEMENTATION
void XonoticHUDScoreDialog_fill(entity me)
{
	entity e;
	string panelname = "score";
	float i;

	me.TR(me);
		me.TD(me, 1, 3, e = makeXonoticCheckBox(0, "hud_panel_score", "Enable panel"));
	me.TR(me);
		me.TD(me, 1, 1.4, e = makeXonoticTextLabel(0, "Background:"));
			me.TD(me, 1, 1.6, e = makeXonoticTextSlider(strzone(strcat("hud_panel_", panelname, "_bg"))));
				e.addValue(e, "Default", "");
				e.addValue(e, "Disable", "0");
				e.addValue(e, strzone(strcat("border_", panelname)), strzone(strcat("border_", panelname)));
				e.configureXonoticTextSliderValues(e);
	me.TR(me);
		me.TDempty(me, 0.2);
		me.TD(me, 1, 1.2, e = makeXonoticTextLabel(0, "Color:"));
		me.TD(me, 2, 2.4, e = makeXonoticColorpickerString(strzone(strcat("hud_panel_", panelname, "_bg_color")), "hud_panel_bg_color"));
			setDependentStringNotEqual(e, strzone(strcat("hud_panel_", panelname, "_bg_color")), "");
	me.TR(me);
		me.TDempty(me, 0.2);
		me.TD(me, 1, 1.2, e = makeXonoticCheckBoxString("", "1 1 1", strzone(strcat("hud_panel_", panelname, "_bg_color")), "Use default"));
	me.TR(me);
		me.TDempty(me, 0.2);
		me.TD(me, 1, 1.2, e = makeXonoticTextLabel(0, "Border size:"));
			me.TD(me, 1, 2.6, e = makeXonoticTextSlider(strzone(strcat("hud_panel_", panelname, "_bg_border"))));
				e.addValue(e, "Default", "");
				e.addValue(e, "Disable", "0");
				for(i = 1; i <= 10; ++i)
					e.addValue(e, strzone(ftos_decimals(i * 2, 0)), strzone(ftos(i * 2)));
				e.configureXonoticTextSliderValues(e);
	me.TR(me);
		me.TDempty(me, 0.2);
		me.TD(me, 1, 1.2, e = makeXonoticTextLabel(0, "Alpha:"));
			me.TD(me, 1, 2.6, e = makeXonoticTextSlider(strzone(strcat("hud_panel_", panelname, "_bg_alpha"))));
				e.addValue(e, "Default", "");
				for(i = 1; i <= 10; ++i)
					e.addValue(e, strzone(ftos_decimals(i/10, 1)), strzone(ftos(i/10)));
				e.configureXonoticTextSliderValues(e);
	me.TR(me);
		me.TDempty(me, 0.2);
		me.TD(me, 1, 1.2, e = makeXonoticTextLabel(0, "Team Color:"));
			me.TD(me, 1, 2.6, e = makeXonoticTextSlider(strzone(strcat("hud_panel_", panelname, "_bg_color_team"))));
				e.addValue(e, "Default", "");
				e.addValue(e, "Disable", "0");
				for(i = 1; i <= 10; ++i)
					e.addValue(e, strzone(ftos_decimals(i/10, 1)), strzone(ftos(i/10)));
				e.configureXonoticTextSliderValues(e);
	me.TR(me);
		me.TDempty(me, 0.4);
		me.TD(me, 1, 3, e = makeXonoticCheckBox(0, "hud_configure_teamcolorforced", "Test the team color in HUD configure mode"));
	me.TR(me);
		me.TDempty(me, 0.2);
		me.TD(me, 1, 1.2, e = makeXonoticTextLabel(0, "Padding:"));
			me.TD(me, 1, 2.6, e = makeXonoticTextSlider(strzone(strcat("hud_panel_", panelname, "_bg_padding"))));
				e.addValue(e, "Default", "");
				for(i = 0; i <= 10; ++i)
					e.addValue(e, strzone(ftos_decimals(i - 5, 0)), strzone(ftos(i - 5)));
				e.configureXonoticTextSliderValues(e);
	me.TR(me);
		me.TD(me, 1, 2, e = makeXonoticTextLabel(0, "Score:"));
	me.TR(me);
		me.TDempty(me, 0.2);
		me.TD(me, 1, 1.2, e = makeXonoticTextLabel(0, "Rankings:"));
		me.TD(me, 1, 2.6/3, e = makeXonoticRadioButton(1, "hud_panel_score_rankings", "0", "Off"));
		me.TD(me, 1, 2.6/3, e = makeXonoticRadioButton(1, "hud_panel_score_rankings", "1", "And me"));
		me.TD(me, 1, 2.6/3, e = makeXonoticRadioButton(1, "hud_panel_score_rankings", "2", "Pure"));
}
#endif
