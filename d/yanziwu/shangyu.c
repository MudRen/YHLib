//ROOM: /d/yanziwu/shangyu.c

inherit ROOM;

int do_jump(string);

void create()
{
        set("short", "����̨");
        set("long",@LONG
վ��̨�ϣ�����Կ���һƬ�ɻ���ǣ���ʱ�м�β����Ծ
��ˮ�棬�е�������������ǰ���·�һ���־Ϳ���ץס��͸��
��Ҷ��Լ���Կ������룬�㲻֪�Ƿ��а���������ȥ��
LONG );
        set("outdoors", "yanziwu");
        set("exits", ([
            "north": __DIR__"shuwu",
        ]));

        setup();
}
