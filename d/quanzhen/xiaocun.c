inherit ROOM;

void create()
{
        set("short", "С��ׯ");
        set("long", @LONG
����һƬС��ׯ��������һ��Сɽ�������ľ����Ƕ�
���ٵ�����ȥ����Ȼ���书�򲻹����塢�����ɽ·��������
Ը�������и�Ů��֯���ճ����������Ъ���ϴ�ͳ��������Ȼ
��ƶ��ȴ������ң��
LONG);
        set("outdoors", "wugong");
        set("exits", ([
                "northwest" : __DIR__"guchang",
                "southdown" : __DIR__"shanlu1",
        ]));
        setup();
        replace_program(ROOM);
}
