#include <ansi.h>
inherit ROOM;

string look_pai();

void create()
{
        set("short", "����С·");
        set("long", @LONG
�������һ����ߵ�һ������С·��һ�Ծ����峺�Ľ�ˮ���а���
�಻�ϵ��һ�������ϼ������Ϯ�ˣ���������۷��ڻ�������衣ǰ
����һ��ľ�� (pai)����·���룬���ڷ紵��ɹ���ּ��Ѿ�ģ���ˡ�
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "southeast" : __DIR__"taohua",
                "northwest" : __DIR__"xiao2",
        ]));

        set("item_desc",([
                "pai" : (: look_pai :),

        ]));
   

        setup();
}

string look_pai()
{
    return
    "\n"
              WHT "          ################################\n"
                  "          ##                            ##\n"
                  "          ##          ͨ     ��         ##\n"
                  "          ##                            ##\n"
                  "          ##        ǰ�����һ�������    ##\n"
                  "          ##    �ڡ�������Σ�ա�����    ##\n"
                  "          ##    ֮�ˡ��Ͻ������롣      ##\n"
                  "          ##                            ##\n"
                  "          ##            �峤  ������    ##\n"
                  "          ##                            ##\n"
                  "          ################################\n\n" NOR;
    "\n";
}
