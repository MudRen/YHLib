inherit BULLETIN_BOARD;

void create()
{
	set_name("�׻� BUG ���԰�", ({ "board" }) );
	set("location", "/d/wizard/bug_room");
	set("board_id", "bug_b");
	set("long", "����ע������������������ݡ�\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}