inherit BULLETIN_BOARD;

void create()
{
	set_name("�������԰�", ({ "board" }) );
	set("location", "/d/wizard/noname_room");
	set("board_id", "noname_b");
	set("long", "˵�ɣ�û��֪�����㡣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}


       