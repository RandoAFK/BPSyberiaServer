modded class ActionCutBookPage
{
	override void OnFinishProgressServer( ActionData action_data )
	{
		SybLogSrv("ActionCutBookPage OnFinishProgressServer");
		
		float decreaseHealth = action_data.m_MainItem.GetMaxHealth() / BOOK_PAGES_COUNT_TO_CUT;
		action_data.m_MainItem.AddHealth("", "", decreaseHealth * -1);
		
		ItemBase paper;
		Class.CastTo(paper, GetGame().CreateObjectEx("Paper", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE) );
		paper.SetQuantity(1, false);
		
		SyberiaSoundEmitter.Spawn("CutPage_SoundEmitter", action_data.m_Player.GetPosition());
	}
};