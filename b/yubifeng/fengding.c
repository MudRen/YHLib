// /guanwai/fengding.c

inherit ROOM;

void create()
{
        set("short", "��ʷ�");
        set("long", @long
ֻ��ɽ���Ժô��������̣���������ǣ�������̻��ʣ�����������ʮ����׳
���⶯�������̣��ֽ����ӷ�����ȥ�������������Σ�����ɮ��Ⱥ��������
�嶥��������վ���������º��ӡ�
long );
        set("exits", ([
                "east"    : __DIR__"damen",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "guanwai");
        setup();
        replace_program(ROOM);
}
