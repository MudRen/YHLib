inherit ROOM;

void create()
{
        set("short", "С��԰");
        set("long", @LONG
���������������С��԰����ֲ��һЩ�в����������Ļ�
ľ��԰������һ����ɽ����ɽ����һ̶СС�Ľ���أ���ˮ��
�����ף��㿴����������ɫ�Ľ����������������յ�������ȥ��
������ͯ����������Ϸ�š�
LONG);
        set("outdoors", "quanzhen");
        set("exits", ([
                "east" : __DIR__"xiaohuayuan3",
                "west" : __DIR__"chanfang3",
                "southwest" : __DIR__"xiaohuayuan1",
        ]));
        set("objects", ([
                __DIR__"npc/daotong" : random(3),
        ]));

        setup();
        replace_program(ROOM);
}
