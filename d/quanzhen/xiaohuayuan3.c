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
                "west" : __DIR__"xiaohuayuan2",
        ]));

        set("objects", ([
                __DIR__"npc/daotong" : random(2),
        ]));

        setup();
        replace_program(ROOM);
}
