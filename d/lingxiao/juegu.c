inherit ROOM;

void create()
{
        set("short","����");
        set("long",@LONG
���ã��������ã���������Ԩ��ˤ��������Ȼˤ������
ѩ���ϣ�����û�����ٸ첲����Ƥ��û�˵�һ�㡣���ǣ�����
�����֮�£������ȥ����һ�����⡣
LONG);
        set("outdoors", "lingxiao");
        set("no_clean_up", 0);
        setup();
} 

void init()
{
    add_action("do_pan", "climb");
}

int do_pan()
{
        object me = this_player();
    	me->move(__DIR__"shiya");
    	return 1;
}

