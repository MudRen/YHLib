inherit ROOM;

void create()
{
        set("short", "��ɽ");
        set("long", @LONG
�����Ǿ���Ⱥ�ɽ���������ƫƧƽʱ���������������
ɽ��ǧ�����֣��������ơ����ױ�����ֻ���ͱھ��գ�������
����
LONG);
        set("outdoors", "jueqing");
        set("exits", ([
               "southeast" : __DIR__"shanlu3",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
