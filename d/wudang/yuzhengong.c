inherit ROOM;

void create()
{
        set("short", "���湬");
        set("long", @LONG
�����ǽ����䵱ɽ�ĵ�һ���������湬�����ޱȣ�����
ǧ��ʳ�ޣ��ǽ���͵�һ��Ъ�Ŵ��������������ڴ˽���������
��˹��й������������������������˱չ��Ѿã����˲�֪
���Ƿ������˼䣬��䴫˵���ѵõ����ţ�����Ĥ�ݡ�
LONG);
        set("objects", ([
                CLASS_D("wudang") + "/zhixiang": 1,
        ]));
        set("outdoors", "wudang");
        set("exits", ([
                "northdown": __DIR__"shijie1",
                "southup"  : __DIR__"wdbl",
        ]));
        setup();
        replace_program(ROOM);
}
