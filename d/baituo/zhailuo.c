inherit ROOM;

void create()
{
        set("short", "Сլ��");
        set("long", @LONG
������һ����Ӱ��涵ľ��׵�Сլ�䣬���з���һ���ں�
�����Ĵ�ˮ�ס�����ɽ�ϳ����ѩ����������˼���һ������
����������������ѩˮ�������е�ˮ��������
LONG);
        set("exits", ([
                "west" : __DIR__"liangong",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "baituo");
        set("resource/water", 1); 
        setup();
        replace_program(ROOM);
}
