inherit ROOM; 
 
void create() 
{ 
	set("short", "��Զ�ھ�");
	set("long", @LONG
���������Զ�ھֵ��ܲ���˵����Զ�ھֵĴ����ڱ�������������������
���˲�֪�����˲�����ÿ��Ľ������ʦ����Ҳ�ܶࡣ������������ͷ�ߴ��ʯ
ʨ�ӡ�������һ�û����������дУ��ڸ��˴���Ժ�ӣ�����Ժ������������
�ġ� 
LONG
	);

	set("exits", ([
  		"enter" : __DIR__"front_yard",
  		"south" : __DIR__"di_anmen",
	]));

  	set("objects", ([
                CLASS_D("zhenyuan") + "/tongzhaohe" : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
        object tong;

        if (dir != "enter" ||
            ! objectp(tong = present("tong zhaohe", this_object())))
                return ::valid_leave(me, dir);

        return tong->permit_pass(me, dir);
}
