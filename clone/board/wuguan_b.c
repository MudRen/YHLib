inherit BULLETIN_BOARD;

void create()
{
        set_name("�����Ҷ����԰�", ({ "board" }) );
        set("location", "/d/wuguan/guofu_dayuan");
        set("board_id", "wuguan_b");
        set("long", "����һ�����ڹ������ӵļҶ��ǽ��������԰塣\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}

