// wangxin.c ����

inherit ITEM;

void create()
{
        set_name("����", ({"shu xin", "shuxin", "xin"}));
        set_weight(100);
        set("value",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
    		set("unit", "��");
            	set("long","����һ���������Һ��ĳ��үд����Զ�ھ�����ͷ��ά��Ļ��š�\n");
		set("header", "��ά������ͷ����");
		set("no_sell", 1);
		set("no_get", "���Ǳ��˵��ţ���ô�����ã�\n");
		set("no_put", 1);
                set("material", "paper");
        }
}