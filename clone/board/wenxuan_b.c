inherit BULLETIN_BOARD;

void create()
{
	set_name("�׻� ��ѡ �����", ({ "board" }) );
	set("location", "/d/wizard/wenxuan");
	set("board_id", "wenxuan_b");
	set("long", "����ע������������������ݡ�\n" );
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}