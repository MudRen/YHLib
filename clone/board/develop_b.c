inherit BULLETIN_BOARD;

void create()
{
	set_name("��Ϸ����������԰�", ({ "board" }) );
	set("location", "/d/wizard/develop_room");
	set("board_id", "develop_b");
	set("long", "����ע������������������ݡ�\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}