inherit ROOM;

void create()
{
        set("short", "�鷿");
        set("long", @long
������ׯ�����鷿�ƿ����ţ��������ı�ͼ�飬��������Ǿ��š�
long );
        set("exits", ([
                "east"    : __DIR__"zoulang3",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}