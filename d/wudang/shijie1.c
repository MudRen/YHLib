inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long",@LONG
������һ����ʵ��ʯ���ϣ���ʱ���н���ʹ���������
����һ�����ͱڣ�һ�������£�̧ͷ��Լ�ɼ������������е�
�����壬������ˮ���ȣ������Ŀ�������
LONG);
        set("objects", ([
                __DIR__"npc/guest" : 2,
        ]));
        set("outdoors", "wudang");
        set("exits", ([
                "northdown"  : __DIR__"xuanyuegate",
                "southup"    : __DIR__"yuzhengong",
        ]));
        setup();
        replace_program(ROOM);
}
