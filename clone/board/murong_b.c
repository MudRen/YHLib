// /clone/board/murong_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("Ľ�ݼҵ������԰�", ({ "board" }) );
	set("location", "/d/yanziwu/canheju");
	set("board_id", "murong_b");
	set("long", "����һ����Ľ�ݼҵ��ӽ��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

