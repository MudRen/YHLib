inherit BULLETIN_BOARD;

void create()
{
	set_name("��ҽ������԰�", ({ "board" }) );
	set("location", "/d/wizard/player_room");
	set("board_id", "heroplayer_b");
	set("long", "�������ڣ��������ԡ�\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}