inherit ROOM;

void create()
{
        set("short", "���Ҵ���");
        set("long", @LONG
�������书�����׸�--��Ա��ҵĴ��ţ����Ϲ���һ���
���ң�����д�ź�������֡���������һ������Ӱ�ڣ�ģ
ģ������������һЩʫ��֮��Ķ�����������ü���۵ļҶ���
ͦ��͹�ǵ�վ���ſ�ҫ��������
LONG);
        set("outdoors", "wugong");
        set("exits", ([
                "north" : __DIR__"dongjie",
                "south" : __DIR__"fu-xiaoyuan",
        ]));
        set("objects", ([
                __DIR__"npc/jiading" : 3,
        ]));

        setup();
        replace_program(ROOM);
}
