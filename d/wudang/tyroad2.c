inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����һ������ʵ��ʯ��·����ʱ���н���ͺ����˴���
������߹���̧ͷ��������ΰ��������������������֮�У�
Ρ��׳�ۡ�����һ��ʯ��ͨ���䵱ɽ���£���Լ�ɼ�Զ���һ�
ƬƬ��������Ŀ��
LONG);
        set("outdoors", "wudang");
        set("exits", ([
                "west" : __DIR__"tyroad1",
                "east" : __DIR__"tyroad3",
        ]));
        set("objects", ([
                __DIR__"npc/guest" : 1
        ]));
        setup();
        replace_program(ROOM);
}
