inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
������һ����ʵ��ʯ���ϣ���ʱ���н���ʹ���������
����һ�����ͱڣ�һ�������£�̧ͷ��Լ�ɼ������������е�
�����壬������ˮ���ȣ������Ŀ�������������һ���Ʒ���
LONG);
        set("objects", ([
                __DIR__"npc/guest" : 1,
        ]));
        set("exits", ([
                "northdown" : __DIR__"shibapan",
                "southup" : __DIR__"zixiaogate",
        ]));
        set("outdoors", "wudang");
        setup();
        replace_program(ROOM);
}
