inherit BULLETIN_BOARD;

void create()
{
        set_name("�嶾�̵������԰�", ({ "board" }) );
        set("location", "/d/wudu/dating");
        set("board_id", "wudu_b");
        set("long", "����һ��ר���嶾�̵���ʹ�õ����԰塣\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}

