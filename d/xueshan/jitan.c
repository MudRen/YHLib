inherit ROOM;

void create()
{
        set("short", "��̳");
        set("long", @LONG
������ѩɽ�µļ�̳���м�һ����̨����ʯ���͡���Χ��
����ľ������ͣ��Ա�һ��ʢˮ��­�����Ű���ֻ���塣һЩ
ʹ��Ϳ�������������������ó��ȡ�
LONG);
        set("outdoors", "xueshan");
        set("no_fight","1");
        set("exits", ([
                "north" : __DIR__"chang",
        ]));
        set("objects", ([
                __DIR__"npc/x_lama": 2,
        ]));
        setup();
        replace_program(ROOM);
}
