inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������Ӵ������鷿�ĳ��ȣ��䲻����ľ����Ҳ���ŵ���
���Ļ��㡣
LONG);
        set("exits", ([
               "east" : __DIR__"dating",
               "west" : __DIR__"shufang",
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
