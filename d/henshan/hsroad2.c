inherit ROOM;

void create()
{
        set("short", "��·");
        set("long", @LONG
������һ����������Ļ���·�ϣ�����������ɭɭ�����֡�
LONG );

        set("outdoors", "hengyang");

        set("exits", ([
                "northwest" : __DIR__"hsroad1",
                "southwest" : __DIR__"hsroad3",
                "southeast" : "/d/fuzhou/fzroad7",
        ]));

        setup();
        replace_program(ROOM);
}
