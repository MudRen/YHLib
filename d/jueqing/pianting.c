inherit ROOM;

void create()
{
        set("short", "ƫ��");
        set("long", @LONG
��������ö������ƫ���������ǹ����к�����̸��Ȳ�
�ĵط����˴������徲��ż��һ������а����ŵ�����������
����һ��˵�������泩��
LONG);
        set("exits", ([
               "west"   : __DIR__"neitang",
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

