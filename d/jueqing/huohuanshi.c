inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
������Ǿ���ȵĻ���ҡ������涨ÿ����һ��ʱ������
�һ�
LONG);
        set("exits", ([
               "south"   : __DIR__"shufang",
               "north"   : __DIR__"danfang",
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
