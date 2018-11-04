#include <ansi.h>

inherit ROOM;

void create ()
{
  	set ("short", "�����");
	set ("long", @LONG
ӭ�ŵ�һ��ɽˮ���Ƿ����ף����������ֱʣ�������һ����ң���������
�������֣�������󡱡�С���ϵ�һ����֬��ƿ���������Ķ��Ǿ�Ө��͸��
�׾գ���֪������˸���¯������һ���������޵İ��㡣һλ��ʦվ��¥�ݿڣ�
������¥��·��Ҳ��֪¥��ס����ʲô�ˡ�
LONG);

  	set("exits", ([
  		"east" : __DIR__"stone_road2",
  		"up" : __DIR__"cabinet2",
	]));

  	set("objects", ([
//        	__DIR__"npc/shangjianming": 1,
        ]));

  	setup();
}

int valid_leave(object me, string dir)
{
    	object guard, *inv, letter;
    	int i;
    	if(dir != "up") return ::valid_leave(me, dir);
    	inv=all_inventory(me);
    	i=sizeof(inv);
    	me->delete_temp("condition/carrying_player");
    	if(objectp(present("shang jianming", environment(me))))
   		guard=present("shang jianming", environment(me));
    	if(!guard) return ::valid_leave(me,dir);
    	while (i--)
    	{
        	if (userp(inv[i]))
            		me->add_temp("condition/carrying_player", 1);
        	continue;
    	}
    	if(me->query_temp("condition/carrying_player"))
    	{
        	return notify_fail(HIC"�̽����ȵ�����λ"+RANK_D->query_rude(me)+
			"������¥���Ȱѱ��ϵ��Ǹ������ˣ�\n"NOR);
    	}
	if(guard) {
    	if(!(letter=present("shu xin", me))
       		||letter->query("header")!="��ά������ͷ����"
     		||me->query("family/family_name")!="������")
    	{
        	return notify_fail(HIC"�̽����ȵ�����ʦ������¥��СϢ���벻Ҫ��ȥ���ţ�\n"NOR);
    	}}
    	return ::valid_leave(me, dir);
}