
inherit ROOM;

void create()
{
        set("short", "ɽ��С��");
        set("long", @LONG
����һ��λ�����ɽ�ţ���Ϊ��֪��С�����������ܹ�ľ
���죬���ֲԴ䣬���ɽ����֦ͷ���񳪺Ͳ����������Ͷ���
��ͨ��ɽ�����
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "southeast" : __DIR__"shanlu14",
                "west"      : __DIR__"shanlu16",
        ]));

        setup();
        replace_program(ROOM);
}
