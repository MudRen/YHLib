inherit ROOM;

void create()
{
        set("short", "�Է�");
        set("long", @LONG
���߽���һ���Է���һ���������޵������˱Ƕ������ٽ�
�黭������ǽ�ϡ�����ɴ�֣������⡣С������Ҥ����ƿ��
���һ�����ʢ��������һ�Ŵ�����ͷ���������Ʊ���
LONG);
        set("exits", ([
                "east" :__DIR__"dating",
        ]));
        set("objects", ([
                __DIR__"npc/binu" : 2,
        ]));
        setup();
        replace_program(ROOM);
}
