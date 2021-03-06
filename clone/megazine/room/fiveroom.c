#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIW "〖地狱〗杂志社社长办公室" NOR);
	set("long", @LONG
这里是〖地狱〗杂志社社长风狐的办公室，你可以看到在墙上挂着他的
照片(picture)，在写字台上有他的名片(card),如果你有什么事，就可以与
与他联系。办公室里面是社长的休息室，你最好不要去打扰他。
LONG
	);

	set("exits", ([ 
                "down" : __DIR__"fourroom",
                "enter" : __DIR__"myhome",
        ]));

        set("item_desc", ([
                "card"    : HIG "风狐 E-MAIL:wfoxd@sina.com  OICQ:47611\n" NOR,
                "picture" : HIG "画上的人物长得宛如玉树临风，风流倜傥，顾盼之间，神采飞扬。真正是人中龙凤！\n" NOR,
        ]));

        set("no_fight",1);   
	setup();
}

int valid_leave(object me, string dir) 
{
        object ob = this_player();

        if (ob->query("id") == "wfoxd" && dir == "enter") 
        {
                message_vision(HIG "$N拿出了一把绿绿地钥匙，轻轻地把门打开，从容的走了进去。\n" NOR, me); 
                return ::valid_leave(me, dir); 
        }

        if (ob->query("id") == "miller" && dir == "enter") 
        {
                message_vision(HIG "$N拿出了一把绿绿地钥匙，轻轻地把门打开，从容的走了进去。\n" NOR, me);  
                return ::valid_leave(me, dir);  
        }

        if (dir == "enter") 
                return notify_fail(HIW "你只见四面八方的空气被一股无形的力量驱动，形成了一堵无形气墙拦住了你的去路。\n" NOR);

        if (dir == "down")
                message_vision(HIG "$N鬼鬼祟祟地东张西望了一会儿，觉得没什么油水可捞,就向下面离开了。\n" NOR, me);

        return ::valid_leave(me, dir);
}
