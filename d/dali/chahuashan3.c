inherit ROOM;

void create()
{
        set("short", "�軨ɽ");
        set("long", @LONG
�����ڲ軨ɽ�ϣ�������������ïʢ�Ĳ軨����Ȼ��
���Ƿ�Ʒ����ż��Ҳ����һ�����Ʒ�������С�������Զ�Ǵ�
��ǵı��š���Щ���������ȥ���ƺ����䳲���ڸ�����
LONG);
        set("outdoors", "dali");
        set("exits", ([
                "south" : __DIR__"chahuashan2",
        ]));
        setup();
        replace_program(ROOM);
}
