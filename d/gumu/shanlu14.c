
inherit ROOM;

void create()
{
        set("short", "ɽ��С��");
        set("long", @LONG
����һ��λ�����ɽ�ţ���Ϊ��֪��С�����������ܹ�ľ
���죬���ֲԴ䣬���ɽ����֦ͷ���񳪺Ͳ����������ɿ���
һ����·����������ͨ��ɽ�����
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "east"      : __DIR__"shanlu13",
                "northwest" : __DIR__"shanlu15",
        ]));

        setup();
        replace_program(ROOM);
}
