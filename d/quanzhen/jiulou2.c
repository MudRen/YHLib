inherit ROOM;

void create()
{
        set("short", "��¥��¥");
        set("long", @LONG
����������������ѧʿ������������ʫ��������������Ҳ
������߳Ժȱ������ס�����Ҳ�ǳ���ٰ�ϲ��ĳ�������վ
��¥��������ֻ�����Ļ�̹��������ȫ�������Ļ�ɳ����֮��
�ϵĻ���������Ƹ��ǺƵ���
LONG);
        set("objects", ([
                __DIR__"npc/zhanggui" : 1,
        ]));

        set("exits", ([
                "down" : __DIR__"jiulou1",
        ]));

        setup();
        replace_program(ROOM);
}
